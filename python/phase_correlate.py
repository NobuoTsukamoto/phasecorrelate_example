#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
    Copyright (c) 2018 Nobuo Tsukamoto

    This software is released under the MIT License.
    See the LICENSE file in the project root for more information.
"""

import cv2
import numpy as np
import argparse

def main():
    # parse args.
    parser = argparse.ArgumentParser()
    parser.add_argument('path_to_src', nargs=None)
    parser.add_argument('path_to_dst', nargs=None)
    args = parser.parse_args()

    # read images
    src_im = cv2.imread(args.path_to_src)
    dst_im = cv2.imread(args.path_to_dst)


    src_im = cv2.cvtColor(src_im, cv2.COLOR_BGR2GRAY)
    dst_im = cv2.cvtColor(dst_im, cv2.COLOR_BGR2GRAY)

    print(np.sum(src_im))

    # src_im = np.float32(src_im)
    # dst_im = np.float32(dst_im)

    src_im = cv2.Laplacian(src_im, cv2.CV_32F)
    dst_im = cv2.Laplacian(dst_im, cv2.CV_32F)

    ret = cv2.phaseCorrelate(src_im, dst_im)

    print(ret)

if __name__ == '__main__':
    main()


