#include <iostream>
#include "Image_Class.h"
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

void greyscale() {
    string filename;
    cout << "Please enter colored image name to turn to gray scale: ";
    cin >> filename;

    Image image(filename);

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned  int avg = 0; // Initialize average value

            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k); // Accumulate pixel values
            }

            avg /= 3; // Calculate average

            // Set all channels to the average value
            image(i, j, 0) = avg;
            image(i, j, 1) = avg;
            image(i, j, 2) = avg;
        }
    }

    cout << "Please enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";

    cin >> filename;
    image.saveImage(filename);
}



void black_white() {
     string filename;
    cout << "Please enter colored image name to turn to black and white: ";
    cin >> filename;

    Image image(filename);

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned  int avg = 0; // Initialize average value

            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k); // Accumulate pixel values
            }

            avg /= 3; // Calculate average

            // Set all channels to the average value
            if (avg < 128){
            image(i, j, 0) = 0;
            image(i, j, 1) = 0;
            image(i, j, 2) = 0;
            }
            else {
            image(i, j, 0) = 255;
            image(i, j, 1) = 255;
            image(i, j, 2) = 255;
            }
        }
    }

    cout << "Please enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";

    cin >> filename;
    image.saveImage(filename);

}

void invert() {
     string filename;
    cout << "Please enter colored image name to turn to invert it: ";
    cin >> filename;

    // Load the image
    Image image(filename);

    // Invert the image
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                // Invert each color channel
                image(i, j, k) = 255 - image(i, j, k);
            }
        }
    }

    // Prompt user for the filename to save the inverted image
    cout << "Please enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> filename;

    // Save the inverted image
    image.saveImage(filename);
}

void flipp_Horiz() {
    string filename;
    cout << "Please enter colored image name to turn to flip it horizontally: ";
    cin >> filename;

    Image image(filename);

    for (int i = 0; i < image.width/2; ++i) {
        for (int j = 0; j < image.height; ++j) {
            // Initialize average value
            for (int k = 0; k < 3; ++k) {
            swap(image( i , j , k ) , image( image.width - 1 - i , j , k )); // Accumulate pixel values
            }
        }
    }

    cout << "Please enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";

    cin >> filename;
    image.saveImage(filename);
}

void flipp_vert() {
     string filename;
    cout << "Please enter colored image name to turn to vertically: ";
    cin >> filename;

    Image image(filename);

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height/2; ++j) {
            // Initialize average value
            for (int k = 0; k < 3; ++k) {
            swap(image( i , j , k ) , image( i ,image.height - 1 - j , k )); // Accumulate pixel values
            }
        }
    }

    cout << "Please enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";

    cin >> filename;
    image.saveImage(filename);
}

void brightnessplus() {
     string filename;
    cout << "Please enter colored image name to bright it: ";
    cin >> filename;

    Image image(filename);

    // Rotate the image by 90 degrees
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < image.channels; ++k) {
                // Flip the pixel values
                if (image( i , j , k ) * 1.5 > 255){
                    image( i , j , k ) = 255;
                }
                else{

                    image( i , j , k ) = image( i , j , k ) * 1.5 ;
                }
            }
        }
    }





    

    // Save the flipped image
    cout << "Please enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> filename;
    image.saveImage(filename);
}

void brightnessminus() {
    string filename;
    cout << "Please enter colored image name to dark it: ";
    cin >> filename;

    Image image(filename);

    // Rotate the image by 90 degrees
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < image.channels; ++k) {

             image( i , j , k ) = image( i , j , k ) * 0.5;     

            }
        }
    }


    // Save the flipped image
    cout << "Please enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> filename;
    image.saveImage(filename);
}

void resizeImage() {
   string filename;
    cout << "Please enter the image name to resize: ";
    cin >> filename;

    Image image(filename);

    int newWidth, newHeight;
    cout << "Enter the new width of the image: ";
    cin >> newWidth;
    cout << "Enter the new height of the image: ";
    cin >> newHeight;

    Image resizedImage(newWidth, newHeight);

    // Calculate the scale factors for width and height
    float scaleX = static_cast<float>(image.width) / newWidth;
    float scaleY = static_cast<float>(image.height) / newHeight;

    // Loop through each pixel in the resized image
    for (int i = 0; i < newWidth; ++i) {
        for (int j = 0; j < newHeight; ++j) {
            // Calculate the corresponding pixel position in the original image
            int originalX = static_cast<int>(i * scaleX);
            int originalY = static_cast<int>(j * scaleY);

            // Set the pixel value in the resized image to the value of the nearest neighbor in the original image
            for (int k = 0; k < image.channels; ++k) {
                resizedImage(i, j, k) = image(originalX, originalY, k);
            }
        }
    }

    // Save the resized image
    cout << "Please enter the name to store the resized image\n";
    cout << "and specify the extension (.jpg, .bmp, .png, .tga): ";
    cin >> filename;
    resizedImage.saveImage(filename);
}

void cropImage() {
       string filename;
    cout << "Please enter the image name to crop: ";
    cin >> filename;

    Image image(filename);

    int startX, startY, newWidth, newHeight;
    cout << "Enter the starting X coordinate of the region to crop: ";
    cin >> startX;
    cout << "Enter the starting Y coordinate of the region to crop: ";
    cin >> startY;
    cout << "Enter the width of the region to crop: ";
    cin >> newWidth;
    cout << "Enter the height of the region to crop: ";
    cin >> newHeight;

    // Create a new image with the specified dimensions
    Image croppedImage(newWidth, newHeight);

    // Copy pixels from the original image to the cropped image
    for (int i = 0; i < newWidth; ++i) {
        for (int j = 0; j < newHeight; ++j) {
            for (int k = 0; k < image.channels; ++k) {
                // Copy pixel values from the original image to the cropped image
                croppedImage(i, j, k) = image(startX + i, startY + j, k);
            }
        }
    }

    // Save the cropped image
    string outputFilename;
    cout << "Please enter the name to store the cropped image\n";
    cout << "and specify the extension (.jpg, .bmp, .png, .tga): ";
    cin >> outputFilename;
    croppedImage.saveImage(outputFilename);
}

void blurImage() {
   string filename;
    cout << "Please enter the image name to blur: ";
    cin >> filename;

    Image image(filename);
    Image blurredImage(image.width, image.height);

    // Define the size of the kernel for averaging
    int kernelSize = 15;


    // Loop through each pixel in the image
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            // Initialize variables to store the sum of pixel values in the kernel
            int sumR = 0, sumG = 0, sumB = 0;

            // Loop through the kernel centered at (i, j)
            for (int di = -kernelSize / 2; di <= kernelSize / 2; ++di) {
                for (int dj = -kernelSize / 2; dj <= kernelSize / 2; ++dj) {
                    // Calculate the coordinates of the pixel in the image
                    int x = i + di;
                    int y = j + dj;

                    // Check if the coordinates are within the image bounds
                    if (x >= 0 && x < image.width && y >= 0 && y < image.height) {
                        // Accumulate pixel values within the kernel
                        sumR += image(x, y, 0);
                        sumG += image(x, y, 1);
                        sumB += image(x, y, 2);
                    }
                }
            }

            // Calculate the average pixel values within the kernel
            int avgR = sumR / (kernelSize * kernelSize);
            int avgG = sumG / (kernelSize * kernelSize);
            int avgB = sumB / (kernelSize * kernelSize);

            // Set the pixel value in the blurred image
            blurredImage(i, j, 0) = avgR;
            blurredImage(i, j, 1) = avgG;
            blurredImage(i, j, 2) = avgB;
        }
    }

    // Save the blurred image
    cout << "Please enter the name to store the blurred image\n";
    cout << "and specify the extension (.jpg, .bmp, .png, .tga): ";
    cin >> filename;
    blurredImage.saveImage(filename);
}

void mergeImages() {
   string filename1, filename2, outputFilename;
    cout << "Enter the filename of the first image: ";
    cin >> filename1;
    cout << "Enter the filename of the second image: ";
    cin >> filename2;

    // Load the first image
    Image image1(filename1);
    // Load the second image
    Image image2(filename2);

    // Determine which image has smaller dimensions
    Image smallerImage = (image1.width * image1.height < image2.width * image2.height) ? image1 : image2;

    // Determine the larger image
    Image largerImage = (smallerImage.width * smallerImage.height < image2.width * image2.height) ? image2 : image1;


    // Resize the larger image to match the dimensions of the smaller one
    Image resizedLarger(smallerImage.width, smallerImage.height);

    float scaleX = static_cast<float>(largerImage.width) / smallerImage.width;
    float scaleY = static_cast<float>(largerImage.height) / smallerImage.height;

    for (int i = 0; i < smallerImage.width; ++i) {
        for (int j = 0; j < smallerImage.height; ++j) {
            int originalX = static_cast<int>(i * scaleX);
            int originalY = static_cast<int>(j * scaleY);
            for (int k = 0; k < 3; ++k) {
                resizedLarger(i, j, k) = largerImage(originalX, originalY, k);
            }
        }
    }

    // Create a new image with the same dimensions as the resized images
    Image mergedImage(smallerImage.width, smallerImage.height);

    // Blend pixel values from both images
    for (int i = 0; i < smallerImage.width; ++i) {
        for (int j = 0; j < smallerImage.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                // Blend pixel values by averaging
                mergedImage(i, j, k) = (image1(i, j, k) + resizedLarger(i, j, k)) / 2;
            }
        }
    }

    // Prompt the user for the output filename
    cout << "Enter the filename to store the merged image: ";
    cin >> outputFilename;

    // Save the merged image
    mergedImage.saveImage(outputFilename);
}


void rotate180(Image& image) {
    int width = image.width;
    int height = image.height;
    Image rotatedImage(width, height);

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            rotatedImage(i, j, 0) = image(width - i - 1, height - j - 1, 0);
            rotatedImage(i, j, 1) = image(width - i - 1, height - j - 1, 1);
            rotatedImage(i, j, 2) = image(width - i - 1, height - j - 1, 2);
        }
    }

    image = rotatedImage;
}

void rotate90(Image& image) {
    int width = image.width;
    int height = image.height;
    Image rotatedImage(height, width);

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            rotatedImage(j, i, 0) = image(i, height - j - 1, 0);
            rotatedImage(j, i, 1) = image(i, height - j - 1, 1);
            rotatedImage(j, i, 2) = image(i, height - j - 1, 2);
        }
    }

    image = rotatedImage;
}

void rotate270(Image& image) {
 int width = image.width;
    int height = image.height;
    Image rotatedImage(height, width);

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            rotatedImage(j, i, 0) = image(width - i - 1, j, 0);
            rotatedImage(j, i, 1) = image(width - i - 1, j, 1);
            rotatedImage(j, i, 2) = image(width - i - 1, j, 2);
        }
    }

    image = rotatedImage;
}
void rotateImage(Image& image, int choice) {
    if (choice == 90)
        rotate90(image);
    else if (choice == 180)
        rotate180(image);
    else if (choice == 270)
        rotate270(image);
}


void addFrame(Image& image, int frameSize, const string& frameColor, const string& frameType) {
    int width = image.width;
    int height = image.height;
    int red = 0, green = 0, blue = 0;

    // Set RGB values based on frame color
    if (frameColor == "red") {
        red = 255;
    } else if (frameColor == "blue") {
        red = 0;  // Baby blue
        green = 102;
        blue = 153;
    } else if (frameColor == "black") {
        // Already initialized as black (0, 0, 0)
    } else if (frameColor == "white") {
        red = 255;
        green = 255;
        blue = 255;
    } else {
        cout << "Invalid frame color. Defaulting to black." << endl;
    }

    // Add the chosen frame type
    if (frameType == "solid") {
        // Solid frame
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < frameSize; j++) {
                image(i, j, 0) = red;
                image(i, j, 1) = green;
                image(i, j, 2) = blue;
            }
        }

        for (int i = 0; i < width; i++) {
            for (int j = height - frameSize; j < height; j++) {
                image(i, j, 0) = red;
                image(i, j, 1) = green;
                image(i, j, 2) = blue;
            }
        }

        for (int j = 0; j < height; j++) {
            for (int i = 0; i < frameSize; i++) {
                image(i, j, 0) = red;
                image(i, j, 1) = green;
                image(i, j, 2) = blue;
            }
        }

        for (int j = 0; j < height; j++) {
            for (int i = width - frameSize; i < width; i++) {
                image(i, j, 0) = red;
                image(i, j, 1) = green;
                image(i, j, 2) = blue;
            }
        }
    } else if (frameType == "fancy") {
        // Fancy frame
        for (int i = 0; i < frameSize; i++) {
            for (int j = i; j < width - i; j++) {
                // Alternating colors
                if ((i / 4) % 2 == 0) {
                    image(j, i, 0) = 255;  // Red
                    image(j, i, 1) = 0;
                    image(j, i, 2) = 0;
                } else {
                    image(j, i, 0) = 0;    // Green
                    image(j, i, 1) = 255;
                    image(j, i, 2) = 0;
                }

                if ((i / 4) % 2 == 0) {
                    image(j, height - 1 - i, 0) = 255;  // Red
                    image(j, height - 1 - i, 1) = 0;
                    image(j, height - 1 - i, 2) = 0;
                } else {
                    image(j, height - 1 - i, 0) = 0;    // Green
                    image(j, height - 1 - i, 1) = 255;
                    image(j, height - 1 - i, 2) = 0;
                }
            }
            for (int j = i; j < height - i; j++) {
                // Alternating colors
                if ((i / 4) % 2 == 0) {
                    image(i, j, 0) = 255;  // Red
                    image(i, j, 1) = 0;
                    image(i, j, 2) = 0;
                } else {
                    image(i, j, 0) = 0;    // Green
                    image(i, j, 1) = 255;
                    image(i, j, 2) = 0;
                }

                if ((i / 4) % 2 == 0) {
                    image(width - 1 - i, j, 0) = 255;  // Red
                    image(width - 1 - i, j, 1) = 0;
                    image(width - 1 - i, j, 2) = 0;
                } else {
                    image(width - 1 - i, j, 0) = 0;    // Green
                    image(width - 1 - i, j, 1) = 255;
                    image(width - 1 - i, j, 2) = 0;
                }
            }
        }
    }
}



void black_white(Image& image) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned int avg = 0; // Initialize average value

            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k); // Accumulate pixel values
            }

            avg /= 3; // Calculate average

            // Set all channels to the average value
            if (avg < 128) {
                image(i, j, 0) = 0;
                image(i, j, 1) = 0;
                image(i, j, 2) = 0;
            }
            else {
                image(i, j, 0) = 255;
                image(i, j, 1) = 255;
                image(i, j, 2) = 255;
            }
        }
    }
}


void Edge_Detection(Image& Image1, Image& Image2) {

    // Prewitt operator kernels
    int prewittX[3][3] = {{-1, 0, 1}, {-1, 0, 1}, {-1, 0, 1}};
    int prewittY[3][3] = {{-1, -1, -1}, {0, 0, 0}, {1, 1, 1}};

    // Iterate over each pixel
    for (int y = 1; y < Image1.height - 1; y++) {
        for (int x = 1; x < Image1.width - 1; x++) {
            for (int z = 0; z < Image1.channels; z++) {
                // Calculate gradient using Prewitt operator
                int gradientX = 0, gradientY = 0;
                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        int pixelX = x + j;
                        int pixelY = y + i;
                        int value = Image1.getPixel(pixelX, pixelY, z);
                        gradientX += value * prewittX[i + 1][j + 1];
                        gradientY += value * prewittY[i + 1][j + 1];
                    }
                }
                // Calculate magnitude of the gradient
                int mag = std::sqrt(gradientX * gradientX + gradientY * gradientY);
                // Invert colors (black to white, white to black)
                mag = 255 - mag;
                Image2.setPixel(x, y, z, mag);
            }
        }
    }
}


int main() {
    int choice;
    while (true) {
        cout << "Which filter do you want to use?" << endl;
        cout << "1. Greyscale filter" << endl;
        cout << "2. Black and White filter" << endl;
        cout << "3. Invert filter" << endl;
        cout << "4. Flip filter" << endl;
        cout << "5. Darken and Lighten filter" << endl;
        cout << "6. Resize Image filter" << endl;
        cout << "7. Crop Image filter" << endl;
        cout << "8. Blur Image filter" << endl;
        cout << "9. Merge filter" << endl;
        cout << "10. Rotate Image filter" << endl;
        cout << "11. Add frame filter" << endl;
        cout << "12. Edge Detection filter" << endl;
        cout << "13. EXIT" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                greyscale();
                break;
            case 2:
                black_white();
                break;
            case 3:
                invert();
                break;
            case 4:
                flipp_Horiz();
                flipp_vert();
                break;
            case 5:
                brightnessplus();
                brightnessminus();
                break;
            case 6:
                resizeImage();
                break;
            case 7:
                cropImage();
                break;
            case 8:
                blurImage();
                break;
            case 9:
                mergeImages();
                break;
            case 10:
                {
                    string filename;
                    cout << "Please enter filename for the image to rotate: ";
                    cin >> filename;
                    Image image(filename);
                    cout << "Enter rotation angle (90, 180, or 270 degrees): ";
                    int rotationChoice;
                    cin >> rotationChoice;
                    rotateImage(image, rotationChoice);
                    cout << "Please enter filename to store the rotated image: ";
                    cin >> filename;
                    image.saveImage(filename);
                    cout << "Rotated image saved successfully." << endl;
                }
                break;

            case 11:
            {
                    string filename1;
                int frameSize;
                string frameColor;
                string frameType;
                
                // Available frame types
                vector<string> frameTypes = {"solid", "fancy"};

                cout << "Enter filename for the image: ";
                cin >> filename1;

                cout << "Enter frame size (normal size = 20): ";
                cin >> frameSize;

                cout << "Enter frame color (red, blue, black, white): ";
                cin >> frameColor;

                cout << "Choose frame type (solid, fancy): ";
                cin >> frameType;

                // Validate frame type
                transform(frameType.begin(), frameType.end(), frameType.begin(), ::tolower); // Convert to lowercase
                if (find(frameTypes.begin(), frameTypes.end(), frameType) == frameTypes.end()) {
                    cout << "Invalid frame type. Defaulting to solid." << endl;
                    frameType = "solid"; // Default to solid frame if invalid type entered
                }

                Image image1(filename1);

                addFrame(image1, frameSize, frameColor, frameType);

                cout << "Enter filename for the new image: ";
                cin >> filename1;

                image1.saveImage(filename1);

                cout << "New image saved successfully." << endl;
                return 0;
            }
                    break;

            case 12:{

                string filename;
                cout << "Enter the filename of the image: ";
                cin >> filename;
                Image Image1(filename);
                // Convert the image to black and white
                black_white(Image1);

                // Create an output image with the same dimensions as the input image
                Image Image2(Image1.width, Image1.height);

                // Perform Sobel edge detection
                Edge_Detection(Image1, Image2);

                string filename2;
                cout << "Enter the filename of the new image: ";
                cin >> filename2;
                Image2.saveImage(filename2);

                cout << "Edge detection complete. New image saved as: " << filename2 << endl;

                return 0;
            }



            
            case 13:
                cout << "Exiting..." << endl;
                return 0;
            
            default:
                cout << "Invalid choice, please enter a valid option." << endl;
        }
    }
    return 0;
}
