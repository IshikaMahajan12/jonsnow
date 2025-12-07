//35.	Implement predicate logic using PROLOG for Vegetable/Fruit Classification.
% --- FACTS (Properties) ---
% botanical_part(Name, PartType).
botanical_part(apple, seed_bearing).
botanical_part(banana, seed_bearing).
botanical_part(tomato, seed_bearing). % Biologically a fruit!
botanical_part(carrot, root).
botanical_part(potato, tuber).
botanical_part(spinach, leaf).
botanical_part(celery, stem).

% taste(Name, Flavor).
taste(apple, sweet).
taste(banana, sweet).
taste(tomato, savory).
taste(lemon, sour).

% color(Name, Color).
color(spinach, green).
color(carrot, orange).
color(lemon, yellow).

% --- RULES (Classification Logic) ---

% 1. Broad Classification (Biological)
% It is a fruit if it is the seed-bearing structure.
type(X, fruit) :- 
    botanical_part(X, seed_bearing).

% It is a vegetable if it is a root, leaf, stem, or tuber.
type(X, vegetable) :- 
    botanical_part(X, Part),
    Part \= seed_bearing. % \= means Not Equal

% 2. Specific Sub-Classifications
identify(X, citrus) :- 
    type(X, fruit), 
    taste(X, sour).

identify(X, root_veg) :- 
    type(X, vegetable), 
    botanical_part(X, root).

identify(X, leafy_green) :- 
    type(X, vegetable), 
    botanical_part(X, leaf),
    color(X, green).

% The "Culinary Vegetable" Rule 
% (Tomatoes are biologically fruits but treated as vegetables in cooking)
culinary_vegetable(X) :- 
    type(X, vegetable).
culinary_vegetable(X) :- 
    type(X, fruit), 
    taste(X, savory).