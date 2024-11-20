#include <iostream>
#include <memory>
#include "./image.h"
#include "./imageBrightener.h"

int main() {
    try {
        auto image = std::make_shared<Image>(512, 512);
        std::cout << "Brightening a 512 x 512 image\n";

        // Create the brightener, passing a shared_ptr to the image
        ImageBrightener brightener(image);

        if (image->IsValid()) {
            int attenuatedCount = brightener.ProcessWholeImage();
            std::cout << "Attenuated " << attenuatedCount << " pixels\n";

            // Access the image again in main, since shared_ptr retains ownership
            std::cout << "Image dimensions: "
                << image->GetRows() << " x " << image->GetColumns() << "\n";
        } else {
            std::cout << "Not a valid image... did nothing\n";
            return 1;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
