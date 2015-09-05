#version 130

in vec4 fragmentColor;
in vec2 fragmentPosition;
in vec2 fragmentUV;
out vec4 color;

uniform float time;

uniform sampler2D mySampler;

void main()
{



//texture 
vec4 textureColor=texture(mySampler,fragmentUV);

//vec4 tint=vec4(fragmentColor.r*(1.0+sin( fragmentPosition.x*fragmentPosition.x+fragmentPosition.y*fragmentPosition.y +time) )*0.5,
		//	(1.0+sin( fragmentPosition.x*fragmentPosition.x+fragmentPosition.y*fragmentPosition.y +time*0.5) )*0.5*fragmentColor.g,
		//	(1.0+sin( fragmentPosition.x*fragmentPosition.x+fragmentPosition.y*fragmentPosition.y +time) )*0.5*fragmentColor.b,
		//	1.0*time);
		
		vec4 tint=vec4(textureColor.r*(1.0+sin(time+(fragmentPosition.x))),textureColor.g*(1.0+sin(time+(fragmentPosition.y))),textureColor.b,1.0*time);
color=tint;


}