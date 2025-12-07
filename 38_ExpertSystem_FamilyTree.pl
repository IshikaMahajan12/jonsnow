//38.	Implement an Expert system using PROLOG for Family Tree. 

% ----- Facts -----
male(john).  female(mary).
male(bob).   female(alice).
male(david). female(emma).

parent(john, bob).   parent(mary, bob).
parent(john, alice). parent(mary, alice).
parent(bob, david).  parent(alice, emma).

% ----- Basic Relations -----
father(F, C) :- male(F), parent(F, C).
mother(M, C) :- female(M), parent(M, C).

sibling(X, Y) :-
    parent(P, X), parent(P, Y), X \= Y.

brother(B, X) :- male(B), sibling(B, X).
sister(S, X) :- female(S), sibling(S, X).

grandparent(G, C) :-
    parent(G, P), parent(P, C).

grandfather(GF, C) :- male(GF), grandparent(GF, C).
grandmother(GM, C) :- female(GM), grandparent(GM, C).

cousin(X, Y) :-
    parent(P1, X), parent(P2, Y), sibling(P1, P2).

ancestor(A, D) :- parent(A, D).
ancestor(A, D) :- parent(P, D), ancestor(A, P).



%?- father(F, bob).
%?- sibling(alice, X).
%?- grandparent(G, emma).
%?- cousin(david, X).
%?- ancestor(john, emma).
