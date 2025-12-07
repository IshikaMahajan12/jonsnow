//34.	Implement predicate logic using PROLOG for Vehicle Classification. 
% --- FACTS (Knowledge Base) ---
% Defining properties of specific vehicles
environment(sedan, land).
environment(truck, land).
environment(harley, land).
environment(bmx_bike, land).
environment(titanic, water).
environment(jet, air).

wheels(sedan, 4).
wheels(truck, 4).
wheels(harley, 2).
wheels(bmx_bike, 2).

has_engine(sedan).
has_engine(truck).
has_engine(harley).
has_engine(titanic).
has_engine(jet).

% Additional distinctive traits
trait(truck, cargo).
trait(sedan, passenger).

% --- RULES (Classification Logic) ---

% 1. Water Vehicles
classify(X, ship) :- 
    environment(X, water).

% 2. Air Vehicles
classify(X, airplane) :- 
    environment(X, air).

% 3. Land: Two-Wheelers
classify(X, motorcycle) :- 
    environment(X, land), 
    wheels(X, 2), 
    has_engine(X).

classify(X, bicycle) :- 
    environment(X, land), 
    wheels(X, 2), 
    \+ has_engine(X). % \+ means NOT

% 4. Land: Four-Wheelers
classify(X, car) :- 
    environment(X, land), 
    wheels(X, 4), 
    trait(X, passenger).

classify(X, heavy_truck) :- 
    environment(X, land), 
    wheels(X, 4), 
    trait(X, cargo).