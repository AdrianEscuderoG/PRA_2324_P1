bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp Node.h

bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/testListArray praA_Array.cpp ListArray.h
bin/testListLinked: testListLinked.cpp ListLinked.h List.h
	mkdir -p bin
	g++ -o bin/testListLinked praA_Linked.cpp ListLinked.h

clean:
	rm -r *.o *.gch bin
