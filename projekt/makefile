all:
	cc main.c komunikacja.c mapa.c cjsonik.c logika.c obrazek.c ../../cJSON/cJSON.c -o odkurzacz -lcurl -lpng

mapka:
	cc mapa.c mapa_t.c -o mapa

komunikacja:
	cc komunikacja_t.c komunikacja.c -o komunikacja -lcurl

cjsonik:
	cc cjsonik.c cjsonik_t.c ../../cJSON/cJSON.c -o cjsonik

cjsonik-test:
	./cjsonik

cjsonik-test-memory:
	valgrind ./cjsonik

test-komunikacja:
	./komunikacja

test-komunikacja-memory:
	valgrind ./komunikacja

test-mapa:
	./mapa

test-mapa-memory:
	valgrind ./mapa

clean:
	rm -f main
	rm -f *.o

test:
	./odkurzacz qwerty_28 bot

test-memory:
	valgrind ./odkurzacz qwerty_28 bot

test-play:
	./odkurzacz qwerty_28 play 