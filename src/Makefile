CFLAGS	=	-D_HPUX_SOURCE	-D_REENTRANT	-Wall	-Wextra	-Werror
OBJECTS	=	main.cpp	connection.cpp	graphviewer.cpp	utils.cpp	user.cpp

rideSharing: $(OBJECTS)
	g++	-std=c++11 $(OBJECTS)	-pthread -o rideSharing

main.o:	utils.h	graphviewer.h	connection.h	edgetype.h	Graph.h	user.h
connection.o:	utils.h	graphviewer.h	connection.h	edgetype.h	Graph.h	user.h 
graphviewer.o:	utils.h	graphviewer.h	connection.h	edgetype.h	Graph.h	user.h
utils.o:	utils.h	graphviewer.h	connection.h	edgetype.h	Graph.h	user.h

clean:
	rm *.o rideSharing
