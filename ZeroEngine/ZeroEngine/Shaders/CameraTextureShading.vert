#version 130

in vec2 vertexPosition;
in vec4 vertexColor;
in vec2 vertexUV;

out vec4 fragmentColor;
out vec2 fragmentPosition;
out vec2 fragmentUV;

uniform mat4 P;
void main()
{
vec4 Pos=P*vec4(vertexPosition.x,vertexPosition.y,0.0,1.0);
gl_Position.xy=(Pos).xy;
gl_Position.z=0.0;
gl_Position.w=1.0;

fragmentPosition=vertexPosition;
fragmentColor=vertexColor;
fragmentUV=vec2(vertexUV.x,1.0-vertexUV.y);//fix for upside down
}