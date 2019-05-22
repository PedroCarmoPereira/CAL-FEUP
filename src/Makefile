CFLAGS	=	-D_HPUX_SOURCE	-D_REENTRANT	-Wall	-Wextra	-Werror
OBJECTS	=	main.cpp	connection.cpp	graphviewer.cpp	utils.cpp	User.cpp

rideSharing: $(OBJECTS)
	g++	-std=c++11 $(OBJECTS)	-pthread -o rideSharing

main.o:	utils.h	graphviewer.h	connection.h	edgetype.h	Graph.h	User.h
connection.o:	utils.h	graphviewer.h	connection.h	edgetype.h	Graph.h	User.h 
graphviewer.o:	utils.h	graphviewer.h	connection.h	edgetype.h	Graph.h	User.h
utils.o:	utils.h	graphviewer.h	connection.h	edgetype.h	Graph.h	User.h
User.o:	utils.h	graphviewer.h	connection.h	edgetype.h	Graph.h	User.h

clean:
	rm *.o rideSharing
