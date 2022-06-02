# Space Connectors #

## Author ##
Sebastian Misztal

## Project Targets ##
- [x] SpaceShip model
- [x] Mine/Bullet model
- [x] Input handler
- [x] Score - saving
- [ ] Score - showing on screen
- [x] Collision detection
- [ ] Collision detection using SDL library

## Ways to improve project ##
* Score - showing, saving, online leaderboard
* Different type of enemies
* SDL collision system
* using threads for collision detection and movement of objects
* Improving Engine - method to add specific type of SpaceShip

## Simplified design model ##
![picture alt](https://github.com/PatientWidar/SpaceConnectors/blob/main/Game_Model.png)

## Documentation ##

### SpaceShip ###
To make new model of SpaceShip, class have to inherit from SpaceShip class. Only then by overriding (or not) method shot model can be used. Same goes to bullets - which can be used in shot method.

### Engine ###
Refresh_rate or size of screen can be set in it.
To edit model of SpaceShip there is need to change it in code.
Adding method in Engine class to add SpaceShip is one of the way to improve that project.

### Textures ###
Every Gameobject use TextureManager to import graphic images.

## In-game view ##
tu bedzie obrazek
