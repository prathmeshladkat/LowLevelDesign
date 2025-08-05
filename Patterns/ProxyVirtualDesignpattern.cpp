#include <iostream>
#include <string>

using namespace std;

class IImage {
    public:
        virtual void display() = 0;
        virtual ~IImage() = default;
};

class RealImage : public IImage {
    string filename;
    public:
        RealImage(string file) {
            this->filename = file;
            //Heavy operations
            cout << "RealImage loading image from disk: " << filename << "\n";
        }

        void display() override {
            cout << "RealImage displaying" << filename << "\n";
        }
};


class ImageProxy : public IImage {
    RealImage* realImage;
    string filename;
    public:
        ImageProxy(string file) {
            this->filename = file;
            realImage = nullptr;
        }

        void display() override {
            //Lazy intialization of RealImage
            if (!realImage) {
                realImage = new RealImage(filename);
            }
            realImage->display();
        }
};

int main() {
    IImage* image1 = new ImageProxy("sample.jpg");
    image1->display();
}