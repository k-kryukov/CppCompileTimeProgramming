all: run-cpp11 run-cpp14 run-cpp17 run-cpp20 clean

clean:
	rm -f *.out

run-cpp11: clean
	g++ -std=c++11 -DCPP11 main.cpp -o program.out && ./program.out

run-cpp14: clean
	echo "No specific code for cpp14"

run-cpp17: clean
	echo "No specific code for cpp17"

run-cpp20: clean
	g++ -std=c++20 -DCPP20 main.cpp -o program.out && ./program.out
