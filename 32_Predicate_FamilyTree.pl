//32.	Implement predicate logic using PROLOG for Family Tree. 
% --- FACTS ---
% gender(Name).
male(john).
male(bob).
male(tom).
male(mike).

female(mary).
female(ann).
female(liz).

% parent(Parent, Child).
parent(john, bob).  % John is Bob's parent
parent(mary, bob).
parent(john, ann).
parent(bob, tom).
parent(bob, liz).
parent(ann, mike).

% --- RULES ---

% X is father of Y if X is a parent of Y AND X is male
father(X, Y) :- parent(X, Y), male(X).

% X is mother of Y if X is a parent of Y AND X is female
mother(X, Y) :- parent(X, Y), female(X).

% X is grandparent of Y if X is parent of Z AND Z is parent of Y
grandparent(X, Y) :- parent(X, Z), parent(Z, Y).

% X is brother of Y if they share a parent Z, X is male, and X is not Y
brother(X, Y) :- parent(Z, X), parent(Z, Y), male(X), X \= Y.

% X is sister of Y if they share a parent Z, X is female, and X is not Y
sister(X, Y) :- parent(Z, X), parent(Z, Y), female(X), X \= Y.

% Recursive Rule: Ancestor
% Base case: X is ancestor of Y if X is parent of Y
ancestor(X, Y) :- parent(X, Y).
% Recursive step: X is ancestor of Y if X is parent of Z AND Z is ancestor of Y
ancestor(X, Y) :- parent(X, Z), ancestor(Z, Y).