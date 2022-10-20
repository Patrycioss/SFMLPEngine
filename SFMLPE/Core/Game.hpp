﻿#pragma once
#include "Scene.hpp"
#include "EventSystem/EventHandler.hpp"

namespace SFMLPE
{
  class Game
  {
  private:
	  std::map<const char*, Scene*> scenesIndex_;
	  static sf::Vector2f sizeF_;
	  static sf::Vector2u sizeU_;
	  
	  sf::Clock clock;
	  float prevTime;
	  
  protected:
	  virtual void Start();
	  virtual void Update();
	  virtual void End();
	  
	  
	  EventHandler eventHandler;
	  
  public:
	  void Run(const int& windowWidth, const int& windowHeight, const char* windowName, const char* resourcePath);
	  
	  void AddScene(const char* name, Scene* scene);
	  void RemoveScene(const char* name);
	  Scene* scene(const char* name);
	  
	  static sf::Vector2f& sizeF();
	  static sf::Vector2u& sizeU();
	  
	  static Game* instance;
	  
	  float deltaTime();
	  sf::Time elapsedTime();
  };
}

