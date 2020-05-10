attribute vec4 position;
attribute vec2 model;
attribute vec2 texCoord; 

varying vec2 v_texCoord;


uniform mat4 model;
// note that we're omitting the view matrix; the view never changes so we basically have an identity view matrix and can therefore omit it.
uniform mat4 projection;

void main()
{
    gl_Position = projection * model * vec4(position.xy, 0.0, 1.0);
    v_textCoord = texCoord;
}