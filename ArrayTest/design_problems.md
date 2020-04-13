#Describing Array implementation design problems
## Main design problems
* No default constructor defined
* No copy constructor defined
* No copy operator defined
* No move operator defined
All above may cause problems with memory leaks, proper destruction of objects and data ownership, considering dynamically allocated class member.
## Others
* Cannot create empty array
