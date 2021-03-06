#version 330

in vec3 InterpolatedColor;
in vec3 InterpolatedNormal;
in vec3 PixelPosition;
in vec2 InterpolatedTexCoord;

out vec4 FragColor;

uniform vec3 LightColor;
uniform vec3 LightPosition;
uniform vec3 CameraPosition;
Uniform sampler2D DiffuseTexture;

void main()
{	
	vec3 ambient = normalize(0.1f * LightColor);
	
	vec3 VecL = normalize(LightPosition - PixelPosition);
	float angleDiffuse = dot(VecL, InterpolatedNormal); 
	if (angleDiffuse < 0)
	{
		angleDiffuse = 0;
	}
	vec3 diffuse = normalize(angleDiffuse * LightColor);


	vec3 VecR = normalize(reflect(-VecL, InterpolatedNormal));
	vec3 VecV = normalize(CameraPosition - PixelPosition);
	float angleSpec = dot(VecR, VecV); 
	if (angleSpec < 0)
	{
		angleSpec = 0;
	}
	vec3 specular = normalize(0.01 * pow(dot(VecV, VecR), 8)* LightColor);

	vec4 R= normalize(mix(vec4 A, vec4 B, 0.5f));



	vec3 phong= normalize((ambient + diffuse + specular)*InterpolatedColor);
	FragColor = texture2D(DiffuseTexture, InterpolatedTexCoord);
	
}