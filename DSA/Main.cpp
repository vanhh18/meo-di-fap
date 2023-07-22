#include "header.h"
#include "encrypted.h"
#include "restored.h"


int main()
{

    Mat image = imread("C:\\Users\\DGC\\Desktop\\startOpencv1\\anh2.jpg", IMREAD_GRAYSCALE);

    if (image.empty())
    {
        cerr << "Unable to read the image." << endl;
        return 1;
    }

   Mat maHoa = encrypted(image);

   Mat giaiMa =  restored(maHoa);

    return 0;
}