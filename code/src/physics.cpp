#include <imgui\imgui.h>
#include <imgui\imgui_impl_sdl_gl3.h>

bool show_test_window = false;

bool play = false;

float reseTime = 2.0f;
float gravity[3] = { 0.0f, -9.81f, 0.0f };

float stretch;
float shear;
float bend;
float particleLife = 2.0f;

float kStretch[2] = { 1000.0f, 50.0f };
float kShear[2] = { 1000.0f, 50.0f };
float kBend[2] = { 1000.0f, 50.0f };
float frictionStretch = 50.0f;

float frictionCoef = 0.0f;
float elasticCoef = 0.0f;

bool useColl = false;
bool sphereColl = false;





void GUI() {
	bool show = true;
	ImGui::Begin("Physics Parameters", &show, 0);

	// Do your GUI code here....
	{	
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);//FrameRate

		ImGui::Checkbox("Play Simulation", &play);
		ImGui::Button("Reset");

		ImGui::SliderFloat("Reset Time", &reseTime, 0.0f, 5.0f);
		ImGui::SliderFloat3("Gravity Scale", &gravity[3], -9.81f, 0.0f);

		if (ImGui::TreeNode("Spring Parameters"))
		{
			ImGui::InputFloat2("k_stretch", &kStretch[2]);
			ImGui::InputFloat2("k_Shear", &kShear[2]);
			ImGui::InputFloat2("k_Bend", &kBend[2]);
			ImGui::SliderFloat("Particle Life", &particleLife, 0.5f, 5.0f);

			ImGui::TreePop();
		}

		if (ImGui::TreeNode("Collisions"))
		{

			ImGui::Checkbox("Use Collisions", &useColl);
			ImGui::Checkbox("Sphere Collisions", &sphereColl);

			ImGui::SliderFloat("Friction Coef.", &frictionCoef, 0.0f, 1.0f);
			ImGui::SliderFloat("Elastic Coef.", &elasticCoef, 0.0f, 1.0f);

			ImGui::TreePop();
		}

		
	}
	// .........................
	
	ImGui::End();

	// Example code -- ImGui test window. Most of the sample code is in ImGui::ShowTestWindow()
	if(show_test_window) {
		ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiSetCond_FirstUseEver);
		ImGui::ShowTestWindow(&show_test_window);
	}
}

void PhysicsInit() {
	// Do your initialization code here...
	// ...................................
}

void PhysicsUpdate(float dt) {
	// Do your update code here...
	// ...........................
}

void PhysicsCleanup() {
	// Do your cleanup code here...
	// ............................
}