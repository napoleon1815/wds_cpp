#NOTICE: must use Tab before g++
person: main.o Person.o #Dog.o
	g++ -o $@ $^

%.o : %.cpp
	g++ -c -o $@ $<

clean:
	rm -rf *.o person
