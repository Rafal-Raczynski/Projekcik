DEPS=main.o komunikacja.o eksploracja.o cjsonik.o ../../cJSON/cJSON.o


odkurzacz: $(DEPS)
	cc $(DEPS) -o $@ -lcurl

%.o:%.c
	cc -c $^ -o $@



clean:
	rm -f main
	rm -f *.o

test:
	./odkurzacz qwerty_28 move explore rotate_right rotate_right explore 