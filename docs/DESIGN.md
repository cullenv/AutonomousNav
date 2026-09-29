# Project Setup: Autonomous Navigation Using Graph Algorithms

## The Goal
Build a C++ autonoumous vehicle routing engine that willfind the most effient path through a city. This project will benchmark against standard BFS against Dijkstra and A*.

## How it works

## Core C++ Classes
Node - our intersections 
    * need id for the node, latidue and longitidude coordiantes
Edges - our roads
    * need distance and time
Graph - either adjacent list or matrix
    * basically our map

## The Custom Feature
**Adding: EV Battery Routing or Left-Turn Penaties**
I either want to add these two. Simulating an electric vehicles battery constrainst. Where a random few nodes within our graph will be designated charging stations while edges will carry a energy drain cost

Or inspired by UPS navigation system avoiding left turns and benchmarking if that is faster. Introducing a time penalty if a left turn is takeing. Inherintly the algoritm does not know what a left turn is so we will have to your the current and previous latitude and longitude corrds to calculate the angle. 

## Map Data
Section of OpenStreetMap data around the Wayne State campus and parsing the XML to build the testing environment

## What we're measuring (Week 6)
* Total route distance and time
* Nodes checked (before optimal route is found)
* Real execution time 
* Memory footprint
* Scalablity (I want to use Open Street Maps for this as it seems pretty cool and moduluar (just parse in a new open street view for any area you want))