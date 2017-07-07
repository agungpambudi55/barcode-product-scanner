# Barcode Product Scanner

Final semester examination of image processing, make a project about detecting product details using the camera by reading the barcode.

## Method
1. Binary image is the image where pixel only has two intensity values ​​0 and 1, where 0 represents the background color (background) and 1 represent the colors
ink / object (foreground) or in shape the number 0 for black and 255 for White color. This binary image is commonly called with monochrome imagery.
2. Cropping on image processing means cut out part of the image so the expected image is obtained. Step This cropping process starts with searching initial and final limits to be made as a sign that the image will be cropped according to its size is desirable. 
3. Thresholding is a process change the image to a degree of gray into binary or black and white imagery so it can be seen which area including objects and backgrounds from the image clearly. How to extract objects from the background is to choose the threshold value T which separates the two that mode. Then for just about anything the dot that meets is called the object point, otherwise called a background point.
4. Bar coding is an artificial form identifier. Barcode is a code machine readable. Barcode consists from a bar and space form (black and white) in the defined ratio represents alphanumeric characters.

## Screenshot
![image-bps][image-url]

[image-url]: https://github.com/agungpambudi55/barcode-product-scanner/blob/master/screenshot.png