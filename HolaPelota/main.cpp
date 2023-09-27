#include <iostream>
#include <Box2d/box2d.h>
#include <cmath>

#ifndef  M_PI
#define M_PI 3.14159265358979323846
#endif

/*
 Ejercicio práctico del día de hoy:
Crear una SImulación en la cual una pelota
 sea lanzada a un angulo de 75° con una Velocidad de 20 Km/h
 */

int main() {

    //Definimos la gravedad
    b2Vec2 gravity(0.0f,-9.8f);

    //construimos el entorno
    b2World world(gravity);

    //hacemos el ground
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);
    b2Body* groundBody = world.CreateBody(&groundBodyDef);

    //Le damos una forma

//declaramos una ball en una posicion y lo hacemos dinamico
b2BodyDef BallBodyDef;
BallBodyDef.type = b2_dynamicBody;//lo convierte en dinamico
BallBodyDef.position.Set(0.0f, 0.0f);
b2Body *BallBody = world.CreateBody(&BallBodyDef);

//se le define el radio a la pelota
b2CircleShape BallShape;
BallShape.m_radius = 1.0f;

b2FixtureDef BallFixtureDef;
BallFixtureDef.shape = &BallShape;
BallFixtureDef.density = 1.0f;
BallBody->CreateFixture(&BallFixtureDef);

float  angle = 75.0f;
float rad_angle = angle * (M_PI/180.0f);
float speed = 5.5555555555555555555555555555556f * 3.6f;
b2Vec2 velocity(speed * std::cos(rad_angle), speed * std::sin(rad_angle));

//simulacion del mundo

float timeStep = 1.0f / 60.0f;
int32 velocityIterations = 8;
int32 positionIterations = 8;

for(int i = 0; i < 60; i++)
{
    world.Step(timeStep, velocityIterations, positionIterations);

    b2Vec2 BallPosition = BallBody->GetPosition();
    b2Vec2 BallSpeedVec = BallBody->GetLinearVelocity();
    float BallSpeed = sqrt(BallSpeedVec.x* BallSpeedVec.x + BallSpeedVec.y * BallSpeedVec.y);
    float KineticEnergy = 0.5f * BallSpeed * BallSpeed;
    std::cout << "Kinetic Energy: " << KineticEnergy << " J\n";
    std::cout << "Ball Speed: " << BallSpeed << " m/s\n";
    std::cout << "Ball Position: (" << BallPosition.x << "," << BallPosition.y << ")\n";
}
//se destruye todo lo utilizado

    world.DestroyBody(BallBody);
    world.DestroyBody(groundBody);
}