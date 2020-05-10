game: program
	em++ blockroll.bc --preload-file fun.png --preload-file sprite.vs --preload-file sprite.frag -O0 -std=c++11 -s WASM=1 -s USE_SDL=2 -s USE_GLFW=3 -O3 -I"C:\Users\PhilipAndAbby\Desktop\web-assembly-introduction-master\BreakoutOpenGL\glm" -o index.html

program:
	emcc sprite_renderer.cpp program.cpp game.cpp resource_manager.cpp shader.cpp texture.cpp -std=c++11 -s WASM=1 -s USE_SDL=2 -s USE_GLFW=3 -O3 -I"C:\Users\PhilipAndAbby\Desktop\web-assembly-introduction-master\BreakoutOpenGL\glm" -o blockroll.bc

run:
	emrun --no_browser --port 5000 .