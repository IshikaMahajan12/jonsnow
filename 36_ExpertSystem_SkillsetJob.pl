//36.	Implement an Expert system using PROLOG for Skillset-Job matching. 
% --- FACTS (Knowledge Base) ---
% has_skill(Person, Skill).

% Alice: The Data Person
has_skill(alice, python).
has_skill(alice, sql).
has_skill(alice, statistics).

% Bob: The Web Developer
has_skill(bob, html).
has_skill(bob, css).
has_skill(bob, javascript).

% Charlie: The Backend Engineer
has_skill(charlie, java).
has_skill(charlie, sql).
has_skill(charlie, git).

% --- RULES (Inference Engine) ---
% Definitions of job requirements

% 1. Data Scientist
% Requires: Python AND SQL AND Statistics
match_role(Person, data_scientist) :-
    has_skill(Person, python),
    has_skill(Person, sql),
    has_skill(Person, statistics).

% 2. Frontend Developer
% Requires: HTML AND CSS AND JavaScript
match_role(Person, frontend_dev) :-
    has_skill(Person, html),
    has_skill(Person, css),
    has_skill(Person, javascript).

% 3. Backend Developer
% Requires: (Java OR C++) AND SQL
match_role(Person, backend_dev) :-
    (has_skill(Person, java) ; has_skill(Person, c_plus_plus)), % ; means OR
    has_skill(Person, sql).

% 4. Full Stack Developer
% Requires: Matching BOTH Frontend AND Backend rules
match_role(Person, full_stack) :-
    match_role(Person, frontend_dev),
    match_role(Person, backend_dev).