#version 130

in vec4 fragmentColor;
in vec2 fragmentPosition;
out vec4 color;

uniform float time;

void main()
{

color=vec4(fragmentColor.r*(cos(fragmentPosition.x*0.0+time)+1)*0.5,
fragmentColor.g*(sin(fragmentPosition.y*18.0+time*-1.0)+1)*0.5,
fragmentColor.b*(sin(fragmentPosition.x*0.2+time)+1)*0.5,
1.0
);


//color=vec4(fragmentPosition.x,fragmentPosition.y,0,cos(1.0*time));




}