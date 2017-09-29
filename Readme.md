[![Travis branch](https://img.shields.io/travis/westernmagic/NumCSE/master.svg)](https://travis-ci.org/westernmagic/NumCSE)
[![AppVeyor branch](https://img.shields.io/appveyor/ci/westernmagic/NumCSE/master.svg)](https://ci.appveyor.com/project/westernmagic/numcse/branch/master)
# NumCSE HS 2017

## Cloning
```
git clone --recursive https://github.com/westernmagic/NumPDE.git
```

Then edit [Settings.cmake](Settings.cmake) appropiately.


## `master` branch
Contains my solutions

### Building
```
cd seriesX
mkdir -p build
cd build
cmake ..
cmake --build .
```

### Testing
```
ctest
```

### Generating submissions
```
cmake --build . --target package_source
```

## `handouts` branch
Contains official handouts

## `solutions` branch
Contains official solutions

