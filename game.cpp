/*******************************************************************
** This code is part of Breakout.
**
** Breakout is free software: you can redistribute it and/or modify
** it under the terms of the CC BY 4.0 license as published by
** Creative Commons, either version 4 of the License, or (at your
** option) any later version.
******************************************************************/
#include "game.h"
#include "resource_manager.h"
#include "sprite_renderer.h"


// Game-related State data
SpriteRenderer* Renderer;


Game::Game(unsigned int width, unsigned int height)
    : State(GAME_MENU), Keys(), Width(width), Height(height)
{

}

Game::~Game()
{
    delete Renderer;
}

std::string vertex_source = 
"attribute vec2 position;   \n"
"attribute vec2 i_texCoords;   \n"
"varying vec2 TexCoords;     \n"
"uniform mat4 model;\n"
"uniform mat4 projection;\n"
"void main()                  \n"
"{                            \n"
"   TexCoords = i_texCoords; \n"
"  gl_Position = projection * model * vec4(position, 0.0, 1.0); \n"
"}                            \n";

std::string texture_load_fragment_source =
"precision mediump float;                            \n"
"attribute vec2 TexCoords;                           \n"
"uniform sampler2D sprite;                        \n"
"uniform vec3 spriteColor; \n"
"varying mediump vec4 color \n"
"void main()                                         \n"
"{                                                   \n"
"  color = vec4(spriteColor, 1.0) * texture(sprite, TexCoords);  \n"
"}                                                   \n";


void Game::Init()
{
    // load shaders
    ResourceManager::LoadShader2(vertex_source.c_str(), texture_load_fragment_source.c_str(), nullptr, "sprite");
    // configure shaders
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->Width),
        static_cast<float>(this->Height), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
    // set render-specific controls
    Shader temp_shader = ResourceManager::getInstance().GetShader("sprite");
    Renderer = new SpriteRenderer(temp_shader);
    // load textures
    ResourceManager::LoadTexture("fun.png", true, "face");
}

void Game::Update(float dt)
{

}

void Game::ProcessInput(float dt)
{

}

void Game::Render()
{
    Texture2D temp_texture = ResourceManager::getInstance().GetTexture("face");
    Renderer->DrawSprite(temp_texture, glm::vec2(200.0f, 200.0f), glm::vec2(300.0f, 400.0f), 45.0f, glm::vec3(0.0f, 1.0f, 0.0f));
}