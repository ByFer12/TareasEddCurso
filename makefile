PROGRAM1 := Torres
COMP := g++
FLAGS := -o

compilar: $(PROGRAM1)

$(PROGRAM1): $(PROGRAM1).cpp
	$(COMP) $(PROGRAM1).cpp $(FLAGS) $(PROGRAM1)


run: 
	./$(PROGRAM1)


clean:
	rm -f $(PROGRAM1)