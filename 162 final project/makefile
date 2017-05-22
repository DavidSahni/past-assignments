a.out: app.cpp mazelevel.hpp mazelevel.o wall.o wall.hpp openspace.o openspace.hpp mazelocation.hpp mazelocation.o ta.o ta.hpp maze.o maze.hpp student.o student.hpp mazeperson.o mazeperson.hpp
	g++ app.cpp mazelevel.o wall.o openspace.o mazelocation.o  maze.o student.o mazeperson.o ta.o -o escape
	 
mazelevel.o: mazelevel.cpp mazelevel.hpp
	g++ mazelevel.cpp -c

mazelocation.o: mazelocation.cpp mazelocation.hpp
	g++ mazelocation.cpp -c

wall.o: wall.cpp wall.hpp
	g++ wall.cpp -c

openspace.o: openspace.hpp openspace.cpp
	g++ openspace.cpp -c

ta.o: ta.cpp ta.hpp
	g++ ta.cpp -c

maze.o: maze.cpp maze.hpp
	g++ maze.cpp -c

student.o: student.cpp student.hpp
	g++ student.cpp -c

mazeperson.o: mazeperson.cpp mazeperson.hpp
	g++ mazeperson.cpp -c

clean:
	rm -f *.o escape
