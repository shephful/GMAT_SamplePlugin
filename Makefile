# $Id: Makefile 35 2012-10-08 16:30:01Z djcinsb $
# SolarSail makefile 
#
# This file calls make on the src folder.

all: 
	cd src; make all

rebuild: 
	cd src; make clean; make all

clean:
	cd src; make clean
