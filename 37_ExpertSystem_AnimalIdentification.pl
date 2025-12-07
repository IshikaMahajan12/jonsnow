//37.	Implement an Expert system using PROLOG for Animal identification. 
% --- FACTS (Knowledge Base) ---
% format: has(Animal, Property).

% Mammals
has(cheetah, hair).
has(tiger, hair).
has(giraffe, hair).
has(zebra, hair).

% Birds
has(ostrich, feathers).
has(penguin, feathers).

% Eating Habits
has(cheetah, meat_eater).
has(tiger, meat_eater).
has(penguin, meat_eater). % Fish
has(giraffe, plant_eater).
has(zebra, plant_eater).
has(ostrich, plant_eater). % Omnivore/Plant mostly

% Physical Traits
has(cheetah, spots).
has(tiger, stripes).
has(zebra, stripes).
has(giraffe, long_neck).
has(ostrich, long_neck).
has(penguin, swims).
has(penguin, black_and_white).

% --- RULES (Inference Engine) ---

% 1. Biological Class Rules
mammal(X) :- has(X, hair).
bird(X)   :- has(X, feathers).

% 2. Diet Rules
carnivore(X) :- has(X, meat_eater).
herbivore(X) :- has(X, plant_eater).

% 3. Identification Rules (The "Expert" Logic)

identify(X, cheetah) :- 
    mammal(X), 
    carnivore(X), 
    has(X, spots).

identify(X, tiger) :- 
    mammal(X), 
    carnivore(X), 
    has(X, stripes).

identify(X, giraffe) :- 
    mammal(X), 
    herbivore(X), 
    has(X, long_neck).

identify(X, zebra) :- 
    mammal(X), 
    herbivore(X), 
    has(X, stripes).

identify(X, ostrich) :- 
    bird(X), 
    has(X, long_neck).

identify(X, penguin) :- 
    bird(X), 
    has(X, swims), 
    has(X, black_and_white).

% Fallback rule
identify(X, unknown) :- \+ is_animal(X).
is_animal(X) :- mammal(X); bird(X).