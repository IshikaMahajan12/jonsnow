//40.	Implement an Expert system using PROLOG for Sentiment Analysis.
% --- FACTS (Patient Data) ---
% Define the symptoms for a patient named 'John'
has_symptom(john, fever).
has_symptom(john, cough).
has_symptom(john, fatigue).
has_symptom(john, loss_of_taste).

% Define symptoms for 'Alice'
has_symptom(alice, runny_nose).
has_symptom(alice, sneezing).

% --- RULES (Medical Knowledge Base) ---

% 1. Covid-19
hypothesis(Patient, covid_19) :-
    has_symptom(Patient, fever),
    has_symptom(Patient, cough),
    (has_symptom(Patient, loss_of_taste) ; has_symptom(Patient, shortness_of_breath)).

% 2. Common Flu (Influenza)
hypothesis(Patient, flu) :-
    has_symptom(Patient, fever),
    has_symptom(Patient, headache),
    has_symptom(Patient, fatigue),
    has_symptom(Patient, chills).

% 3. Common Cold
hypothesis(Patient, cold) :-
    has_symptom(Patient, runny_nose),
    has_symptom(Patient, sneezing),
    \+ has_symptom(Patient, fever). % Colds rarely have fever

% 4. Measles
hypothesis(Patient, measles) :-
    has_symptom(Patient, fever),
    has_symptom(Patient, runny_nose),
    has_symptom(Patient, rash).

% --- ENTRY POINT ---
% A helper rule to print the diagnosis neatly
diagnose(Patient) :-
    hypothesis(Patient, Disease),
    write(Patient), write(' probably has '), write(Disease), nl.

diagnose(Patient) :-
    \+ hypothesis(Patient, _),
    write('Sorry, I cannot identify the disease for '), write(Patient), nl.