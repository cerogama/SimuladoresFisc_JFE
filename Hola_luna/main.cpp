#include <iostream>
#include <Box2d/Box2d.h>

int main() {
    //definimos el entorno en el que se ejecuta la acción
    b2Vec2 gravity(0.0f, -1.623f);
    b2World world(gravity);

    //creamos el suelo para que colisione
    b2BodyDef grounBodyDef;
    grounBodyDef.position.Set(0.0f, -10.0f);
    b2Body *groundBody = world.CreateBody(&grounBodyDef);

    //le creamos la forma al poligono con sus dimenciones
    b2PolygonShape groundBox;
    groundBox.SetAsBox(50.0f, 10.0f);

    groundBody->CreateFixture(&groundBox, 0.0f);


    //ya creado el entorno ahora le toca a la figura que se estara moviendo en este
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 15.0f);
    b2Body *body = world.CreateBody(&bodyDef);

    //Creamos los fixes para la figura en la que le daremos las propiedades deseadas
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 15600.0f;
    fixtureDef.friction = 0.0f;

    //le mandamos la direccion de memoria del body(cuerpo) a las fxture (valores)
    body->CreateFixture(&fixtureDef);

    float timeStep = 1.0f;

    int32 velocityIteration = 6;
    int32 positionIteration = 2;

    for (int32 i = 0; i < 60; ++i) {
        world.Step(timeStep, velocityIteration, positionIteration);
        b2Vec2 position = body->GetPosition();
        float angle = body->GetAngle();
        printf("%4.2f %4.2f %4.2f\n", position.x,position.y,angle);
    }



}
