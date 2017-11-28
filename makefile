CXX = g++
TIME = time
INPUT = input.txt


all: fermat miller solovay atkin segmented sundaram time
fermat: pfermat.cpp
	$(CXX) $? -o $@ < INPUT
miller: pmillerrabin.cpp
	$(CXX) $? -o $@ < INPUT
solovay: psolovaystrassen.cpp
	$(CXX) $? -o $@ < INPUT
atkin: satkin.cpp
	$(CXX) $? -o $@ < INPUT
segmented: ssegmented.cpp
	$(CXX) $? -o $@ < INPUT
sundaram: ssundaram.cpp
	$(CXX) $? -o $@ < INPUT

time: time-atkin time-fermat time-miller time-solovay time-sundaram time-segmented
time-atkin: atkin
	(TIME ./$?;) 2> ./outputs/$?.txt
time-fermat: fermat
	(TIME ./$?;) 2> ./outputs/$?.txt
time-miller: miller
	(TIME ./$?;) 2> ./outputs/$?.txt
time-solovay: solovay
	(TIME ./$?;) 2> ./outputs/$?.txt
time-sundaram: sundaram
	(TIME ./$?;) 2> ./outputs/$?.txt
time-segmented: segmented
	(TIME ./$?;) 2> ./outputs/$?.txt

clean: atkin fermat miller solovay sundaram segmented
	rm $?
