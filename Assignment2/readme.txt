# Description

An implementation of the stable matching algorithm(Gale-Shapley algorithm). It solves the problem of finding a stable matching between two sets of elements, where each element in one set has a preference list of elements from the other set. In this case, the problem is about matching men and women based on their preferences.

The algorithm works as follows:

1. Read the input data, including the number of men and women and their preference lists.
2. Initialize arrays and maps to store information about the matching process.
3. Iterate through the unmatched men and have them propose to women until all men are matched.
4. For each proposal, the woman evaluates her options and selects the best candidate based on her preference list.
5. If a woman has no followers, she accepts the proposal. Otherwise, she compares the current candidate with her existing follower and makes a decision.
6. The algorithm continues until all men are matched.
7. Finally, the resulting stable matching is outputted.