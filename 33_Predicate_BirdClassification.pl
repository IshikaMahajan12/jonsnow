//33.	Implement predicate logic using PROLOG for Bird classification. 
% --- FACTS (The Knowledge Base) ---
% Properties of specific bird instances
has_feathers(eagle).
has_feathers(penguin).
has_feathers(ostrich).
has_feathers(canary).

can_fly(eagle).
can_fly(canary).

cannot_fly(penguin).
cannot_fly(ostrich).

trait(eagle, eats_meat).
trait(penguin, swims).
trait(ostrich, tall).
trait(canary, yellow).

% --- RULES (The Logic) ---

% 1. General definition: It is a bird if it has feathers
is_bird(X) :- has_feathers(X).

% 2. Classification Logic
identify(X, raptor) :- 
    is_bird(X), 
    can_fly(X), 
    trait(X, eats_meat).

identify(X, songbird) :- 
    is_bird(X), 
    can_fly(X), 
    trait(X, yellow).

identify(X, antarctic_bird) :- 
    is_bird(X), 
    cannot_fly(X), 
    trait(X, swims).

identify(X, flightless_runner) :- 
    is_bird(X), 
    cannot_fly(X), 
    trait(X, tall).