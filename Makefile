sort:main.cpp
	g++ -o $@ $^ -g

.PHONY:clean
clean:
	rm -rf sort
