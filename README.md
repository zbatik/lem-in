# lem-in
## A 42 algorithms I project
### Overview
Lem-in is C programming project in path finding and graph data structures. The premise is to walk vertural ants along the shortest path though an ant colony (a graph).
### The map (the graph)
The graph is defined by in a text file with the following specifications:
    * The first line of the file supplies the number of ants
    * A room in the colony (or node in the graph) is given on its own line with the following format
        * room_name coordinates (e.g. start_room 2 1)
    * A path between two rooms (or link edge between two nodes) is defined thus:
        * room1-room2
    * the start and end room are the rooms following the ##start and ##end lines
    * comments are specified by a single #

Bellow is a example of a input map:
![Sample Input](http://oi63.tinypic.com/2zhjw3s.jpg)
and it has the following graph representation:
![Graph Representation](http://oi64.tinypic.com/352rxfn.jpg)
### Usage
```
make
```
