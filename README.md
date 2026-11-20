# 🐣 S1 | Prog: Workshop


## Exercices ⭐:

**Ne garder que le vert**

![mimi](/output/img_vert.png)

**Channel swap**

![mimi](/output/channel_swap.png)

**Black and white**

![mimi](/output/b_and_w.png)

**Negative**

![mimi](/output/negative.png)

**Gradient**

![mimi](/output/gradient.png)

## Exercices ⭐⭐:

**Mirror**

![mimi](/output/mirror.png)

**Noise**

![mimi](/output/noise.png)

**Rotation**

![mimi](/output/rotation.png)

J'ai eu un petit problème avec la rotation, puisque mon image était inversée avant d'être à 90°, ce qui me donnait quelque chose comme ça:

![mimi](/output/failed_rotation.png)

Mon programme ne fonctionnait pas car mes pixels de coordonnées x=y ne changeaient pas de place. J'ai donc transformé mon code passant de cette version:

```cpp
image.pixel(y,x)=seb.pixel(x,y);
```

à celle-ci:

```cpp
image.pixel(image.height()-y-1,x)=seb.pixel(x,y);
```

**RGB split**

![mimi](/output/rgb_split.png)

**Lighter**

![mimi](/output/lighter.png)

**Darker**

![mimi](/output/darker.png)

**Disc**

![mimi](/output/disc.png)

**Circle**

![mimi](/output/circle.png)

**Animation**

![mimi](/output/animation.gif)

**Mosaic**

![mimi](/output/mosaic.png)

## Exercices ⭐⭐⭐:

**Rosace**

![mimi](/output/rosace.png)

**Glitch**

![mimi](/output/glitch.png)

**Fractale**

![mimi](/output/fractale.png)

**Colored gradient**

![mimi](/output/colored_gradient.png)

## Exercices ⭐⭐⭐⭐:

**Mosaic mirror**

![mimi](/output/mosaic_mirror.png)

**Vortex**