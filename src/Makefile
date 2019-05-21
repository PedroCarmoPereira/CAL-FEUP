CFLAGS	=	-D_HPUX_SOURCE	-D_REENTRANT	-Wall	-Wextra	-Werror
OBJECTS	=	main.o	connection.o	graphviewer.o	utils.o

rideSharing: $(OBJECTS)
	clang++ $(OBJECTS)	-pthread -o rideSharing

main.o:	utils.h	graphviewer.h	connection.h	edgetype.h
connection.o:	utils.h	graphviewer.h	connection.h	edgetype.h
graphviewer.o:	utils.h	graphviewer.h	connection.h	edgetype.h
utils.o:	utils.h	graphviewer.h	connection.h	edgetype.h

clean:
	rm *.o rideSharing
