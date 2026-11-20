#include <sil/sil.hpp>
#include <random.hpp>
#include <glm/gtx/matrix_transform_2d.hpp>
#include <complex>

void img_vert(sil::Image& image){
    for (glm::vec3& color : image.pixels()){
        color.r = 0.f;
        color.b = 0.f;
    }
}

void channel_swap(sil::Image& image){
    for (glm::vec3& color : image.pixels()){
        float rouge = color.r;
        float vert = color.g;
        float bleu = color.b;
        color.r = bleu;
        color.b=vert;
        color.g=rouge;
    }
}

void b_and_w(sil::Image& image){
    for(glm::vec3& color: image.pixels()){
        float moy = (color.r+color.b+color.g)/3;
        color.r = moy;
        color.g = moy;
        color.b = moy;
    }
}

void negative(sil::Image& image){
    for(glm::vec3& color: image.pixels()){
        color.r=1-color.r;
        color.b=1-color.b;
        color.g=1-color.g;
    }
}

void gradient(sil::Image& image){
    for (int x=0; x < image.width(); x++){
        for (int y=0; y < image.height(); y++){
            image.pixel(x, y).r = x/static_cast<float>(image.width());
            image.pixel(x, y).b = x/static_cast<float>(image.width());
            image.pixel(x, y).g = x/static_cast<float>(image.width());
        }
    }
}

void mirror(sil::Image& image){
    sil::Image copy {image};
    for (int x=0; x < image.width(); x++){
        for (int y=0; y < image.height(); y++){
            image.pixel(x,y) = copy.pixel(copy.width()-x-1,y);
        }
    }
}

void noise(sil::Image& image){
    for (int y=0; y < image.height(); y++){
        for(int i=0; i<50; i++){
            int random = random_int(0,500);
            float random_red = random_float(0,1);
            float random_green = random_float(0,1);
            float random_blue = random_float(0,1);
            image.pixel(random, y).r=random_red;
            image.pixel(random, y).g=random_green;
            image.pixel(random, y).b=random_blue;
        }
    }
}

void rotation(sil::Image& image){
    sil::Image seb {"images/photo.jpg"};
    for(int x=0; x<image.width(); x++){
        for(int y=0; y<image.height(); y++){
            image.pixel(y,x)=seb.pixel(x,y);
        }
    }
}

void rgb_split(sil::Image& image){
    sil::Image logo {"images/rafou.jpg"};
    for(int x=10; x<image.width()-10; x++){
        for(int y=0; y<image.height(); y++){
            image.pixel(x,y).r=logo.pixel(x-10,y).r;
            image.pixel(x,y).b=logo.pixel(x+10,y).b;
        }
    }
}

void lighter(sil::Image& image){
    for (glm::vec3& color : image.pixels()){
        color.r += 0.3;
        color.g += 0.3;
        color.b += 0.3;
    }
}

void darker(sil::Image& image){
    for (glm::vec3& color : image.pixels()){
        color.r -= 0.3;
        color.g -= 0.3;
        color.b -= 0.3;
    }
}

void disc(sil::Image& image){
    for (int x=0; x < image.width(); x++){
        for (int y=0; y < image.height(); y++){
            int xtranslate = x - 16*image.width()/16;
            int ytranslate = y - image.height()/2;
            if(xtranslate*xtranslate + ytranslate*ytranslate < 150*150){
                image.pixel(x, y).r = 1;
                image.pixel(x, y).g = 1;
                image.pixel(x, y).b = 1;
            }
        }
    }
}

void circle(sil::Image& image, int xtranslate, int ytranslate){
    for (int x=0; x < image.width(); x++){
        for (int y=0; y < image.height(); y++){
            if((x-xtranslate)*(x-xtranslate) + (y-ytranslate)*(y-ytranslate) > 100*100 && (x-xtranslate)*(x-xtranslate) + (y-ytranslate)*(y-ytranslate) < 104*104){
                image.pixel(x, y).r = 1;
                image.pixel(x, y).g = 1;
                image.pixel(x, y).b = 1;
            }
        }
    }
}

void rosace(sil::Image& image){
    circle(image, image.width()/2, image.height()/2);
    int xtranslate = image.width()/2;
    int ytranslate = image.height()/2;
    float const pi = 2*acos(0.0);
    for(int i=0; i<12; i++){
        circle(image, xtranslate + 102*cos(i*pi/6), ytranslate + 102*sin(i*pi/6));
    }
}

void mosaic(sil::Image& image){
    sil::Image copy {image};
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            for (int x=0; x < image.width(); x++){
                for (int y=0; y < image.height(); y++){
                    if(x%5 == 0 && y%5 == 0){
                        image.pixel(x/5+i*image.width()/5,y/5+j*image.height()/5) = copy.pixel(x,y);
                    }
                }
            }
        }
    }
}

void mosaic_mirror(sil::Image& image){
    sil::Image copy {image};
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            for (int x=0; x < image.width(); x++){
                for (int y=0; y < image.height(); y++){
                    if(x%5 == 0 && y%5 == 0){
                        if(i%2==0){
                            if(j%2==0){
                                image.pixel(x/5+i*image.width()/5,y/5+j*image.height()/5) = copy.pixel(image.width()-x-1,image.height()-y-1);
                            } else {
                                image.pixel(x/5+i*image.width()/5,y/5+j*image.height()/5) = copy.pixel(image.width()-x-1,y);
                            }
                        } else if(j%2==0){
                            image.pixel(x/5+i*image.width()/5,y/5+j*image.height()/5) = copy.pixel(x,image.height()-y-1);
                        } else {
                            image.pixel(x/5+i*image.width()/5,y/5+j*image.height()/5) = copy.pixel(x,y);
                        }
                    }
                }
            }
        }
    }
}

void glitch(sil::Image& image){
    sil::Image copy{image};
    for(int nb=0; nb<200; nb++){
        int a= random_int(0,8);
        int x= random_int(0,image.width()-26);        
        int y= random_int(0,image.height()-11);
        int randomx = random_int(0,image.width()-26);
        int randomy = random_int(0,image.height()-11);
        for(int i=0; i<random_int(10,25); i++){
            for(int j=0; j<a; j++){
                image.pixel(randomx+i,randomy+j)=copy.pixel(x+i,y+j);
            }
        }
    }
}

void fractale(sil::Image& image){
    for(int x=0; x<image.width()-1; x++){
        for(int y=0; y<image.height()-1; y++){
            std::complex<float> z{0.f, 0.f};
            std::complex<float> c{(x-250)/125.f,(y-250)/125.f};
            for(int a=0; a<100; a++){
                z+= z*z + c;
            }
            if(std::abs(z) < 2){
                image.pixel(x,y).r = 1;
                image.pixel(x,y).g = 1;
                image.pixel(x,y).b = 1;
            }
        }
    }
}

void colored_gradient(sil::Image& image){   
    for (int x=0; x < image.width(); x++){
        for (int y=0; y < image.height(); y++){
            float temp= x/static_cast<float>(image.width());
            image.pixel(x, y).r = temp;
            image.pixel(x, y).b = 1-temp;
        }
    }
}


int main()
{
    { //img vert
        sil::Image image {"images/photo.jpg"};
        img_vert(image);
        image.save("output/img_vert.png");
    }
    
    { //channel swap
        sil::Image imac {"images/imac.png"};
        channel_swap(imac);
        imac.save("output/channel_swap.png");
    }

    { //black&white
        sil::Image image {"images/photo.jpg"};
        b_and_w(image);
        image.save("output/b_and_w.png");
    }

    { //negative
        sil::Image imac {"images/imac.png"};
        negative(imac);
        imac.save("output/negative.png");
    }

    { //gradient
        sil::Image image{400/*width*/, 200/*height*/};
        gradient(image);
        image.save("output/gradient.png");
    }

    { //mirror
        sil::Image frog {"images/frog.jpg"};
        mirror(frog);
        frog.save("output/mirror.png");
    }

    { //noise
        sil::Image frog {"images/frog.jpg"};
        noise(frog);
        frog.save("output/noise.png");
    }

    { //rotation
        sil::Image seb {"images/photo.jpg"};
        rotation(seb);
        seb.save("output/rotation.png");
    }

    { //rgb split
        sil::Image rafou {"images/rafou.jpg"};
        rgb_split(rafou);
        rafou.save("output/rgb_split.png");
    }

    { //lighter
        sil::Image frog {"images/frog.jpg"};
        lighter(frog);
        frog.save("output/lighter.png");
    }

    { //darker
        sil::Image frog {"images/frog.jpg"};
        darker(frog);
        frog.save("output/darker.png");
    }

    { //disc
        sil::Image image{500/*width*/, 500/*height*/};
        disc(image);
        image.save("output/anim16.png");
    }

    { //circle
        sil::Image image{500/*width*/, 500/*height*/};
        circle(image, image.width()/2, image.height()/2);
        image.save("output/circle.png");
    }

    { //rosace
        sil::Image image{500/*width*/, 500/*height*/};
        rosace(image);
        image.save("output/rosace.png");
    }

    { //mosaic
        sil::Image rafou{"images/rafou.jpg"};
        mosaic(rafou);
        rafou.save("output/mosaic.png");
    }

    { //mosaic mirror
        sil::Image rafou{"images/rafou.jpg"};
        mosaic_mirror(rafou);
        rafou.save("output/mosaic_mirror.png");
    }

    { //glitch
        sil::Image imac{"images/imac.png"};
        glitch(imac);
        imac.save("output/glitch.png");
    }

    { //fractale
        sil::Image image{500/*width*/, 500/*height*/};
        fractale(image);
        image.save("output/fractale.png");
    }

    { //colored gradient
        sil::Image image{500/*width*/, 500/*height*/};
        colored_gradient(image);
        image.save("output/colored_gradient.png");
    }
}