# PhaseCorrelate examples (Python / C++).

## About
OpenCV PhaseCorrelate examples (Python / C++).<br>
See here for details of [PhaseCorrelate API](https://docs.opencv.org/3.4.4/d7/df3/group__imgproc__motion.html#ga552420a2ace9ef3fb053cd630fdb4952).

## Environment
- OpenCV 3.4.4 (or higher)

## How to build (C++ examples)
``` 
$ cd cplus
$ cmake .
$ make
```

## How to use

# C++
phase_corr <PATH_TO_SRC_IMAGE_FILE> <PATH_TO_DST_IMAGE_PATH><br>
Outputs the displacement (pixel unit) in X and Y directions. 
``` 
$ ./phase_corr ../lena_src.jpg ../lena_dst.jpg 
3.0277, 3.98623
``` 

# Python
phase_correlate.py <PATH_TO_SRC_IMAGE_FILE> <PATH_TO_DST_IMAGE_PATH><br>
Outputs the correlation value in addition to the deviation in the X and Y directions.
```
python3 phase_correlate.py ../lena_src.jpg ../lena_dst.jpg
((3.0276976107825533, 3.986227864315339), 0.8357693982543424)
```
