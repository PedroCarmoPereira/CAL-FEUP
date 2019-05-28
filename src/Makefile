CFLAGS	=	-D_HPUX_SOURCE	-D_REENTRANT	-Wall	-Wextra	-Werror
OBJECTS	=	main.cpp	connection.cpp	graphviewer.cpp	utils.cpp	User.cpp Driver.cpp RideShare.cpp HK.cpp
#OBJECTS	=	main.o	connection.o	graphviewer.o	utils.o	User.o Driver.o RideShare.o HK.o

rideSharing: $(OBJECTS)
	g++	-std=c++11 $(OBJECTS)	-pthread -o rideSharing

main.o:	utils.h	graphviewer.h	connection.h	edgetype.h	Graph.h	User.h Driver.h RideShare.h HK.h
connection.o:	utils.h	graphviewer.h	connection.h	edgetype.h	Graph.h	User.h Driver.h  RideShare.h HK.h
graphviewer.o:	utils.h	graphviewer.h	connection.h	edgetype.h	Graph.h	User.h Driver.h RideShare.h HK.h
utils.o:	utils.h	graphviewer.h	connection.h	edgetype.h	Graph.h	User.h Driver.h RideShare.h HK.h
User.o:	utils.h	graphviewer.h	connection.h	edgetype.h	Graph.h	User.h Driver.h RideShare.h HK.h

clean:
	rm *.o rideSharing
