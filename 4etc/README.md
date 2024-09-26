# Prehistoric

A small platformer like videogame.

Requirements :
	CMake verion 3.10 or above.
	SDL2 library.
	Doxygen software installed.

Available commands :
  "cmake CMakeLists.txt" : Creates the makefile for the project.
  "make" : Creates an launchable version of the project.
  "make clean" : Removes all compiled files.
	"make doxygen" : Generates an HTML documentation of the Project.

  "./Prehistoric" : after using the command "make", launches the program.

Please refer to CHANGELOG.txt to see if the project is compilable.


Also, make sure that the SL2, SDL-TTF and SDL-MIXER libraries are correctly installed.

Here's a list of commands to make sure they are all there and up to date.

sudo apt-get install libsdl-image1.2 libsdl-image1.2-dev  (for the Image Library)
sudo apt-get install libsdl-ttf2.0-0 libsdl-ttf2.0-dev  (for the ttf library)
