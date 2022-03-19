#include "theodorusSpiral.h"
#include <raylib.h>
#include <rlgl.h>
#include <math.h>

int triangles;
int antialiasing;
int zoom;

const unsigned int screenWidth = 800;
const unsigned int screenHeight = 800;

static int index;
static float *rotation;

void init()
{
    rotation = malloc(triangles*sizeof(float));

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetConfigFlags(FLAG_MSAA_4X_HINT * (antialiasing-1));
    InitWindow(screenWidth,screenHeight,"Theodorus Spiral");

    setAngles();
    reset();
}

void setAngles()
{
    rotation[0] = 0;
    for (int i = 1; i < triangles; i++)
    {
        rotation[i] = rotation[i-1]+atan(1/sqrt(i))*(180/PI);
    }
}

void reset()
{
    ClearBackground(BLACK);
    index = 0;

    system("clear");
    printf("Triangles = %d\nZoom = %d\n", triangles, zoom);
}

void update()
{
    if (IsWindowResized())
        reset();

    if (GetMouseWheelMove()!=0 && zoom+GetMouseWheelMove() > 0)
    {
        reset();
        zoom += GetMouseWheelMove();
    }

    if (IsKeyPressed(KEY_RIGHT))
    {
        reset();
        triangles++;
        rotation = realloc(rotation, triangles*sizeof(float));
        setAngles();
    }
    else if (IsKeyPressed(KEY_LEFT))
    {
        reset();
        triangles--;
    }
}

void draw()
{
    if (index < triangles)
    {
        rlTranslatef(GetScreenWidth()/2,GetScreenHeight()/2,0);

        rlPushMatrix();
            rlRotatef(rotation[index],0,0,-1);
            DrawTriangle((Vector2){0,0}, (Vector2){(sqrt(index+1)*zoom),0},(Vector2){(sqrt(index+1)*zoom),-zoom},(Color){0,158,47,50});
            DrawTriangleLines((Vector2){0,0}, (Vector2){(sqrt(index+1)*zoom),0},(Vector2){(sqrt(index+1)*zoom),-zoom},(Color){0,158,47,255});
        rlPopMatrix();
    }
}

void run()
{
    init();

    while (!(WindowShouldClose()))
    {
        update();

        BeginDrawing();

        draw();

        EndDrawing();

        if (index < triangles)
            index++;
    }

    CloseWindow();
}
