# include <Siv3D.hpp>

void Main()
{
	//背景の設定
	Scene::SetBackground(ColorF{ 0.8, 0.9, 1.0 });

	//テキストボックスの定義
	TextEditState te;

	const Font font{ 30 };

	Array<String> key_list;
	String keys = U"";
	String result = U"";

	constexpr Rect key_list_window	{ 25 , 100, 275, 450 };
	constexpr Rect result_window	{ 400, 100, 275, 450 };

	while (System::Update())
	{
		
		

		SimpleGUI::TextBox(te, Vec2{ 0, 10 });


		auto submit = SimpleGUI::Button(U"Submit", Vec2{ 220, 10 });
		auto calc = SimpleGUI::Button(U"Calc", Vec2{ 340, 10 });

		if (submit) {
			key_list << te.text;
			keys += te.text + U"\n";
			// テキストを消去
			te.clear();
		}

		if (calc) {
			result = U"";
			if (key_list.size() == 0) {
				continue;
			}
			result += key_list[Random(key_list.size() - 1)];
			
		}

		
		int i = 0;

		key_list_window.draw(ColorF{ 0.3 });
		
		result_window.draw(ColorF{ 0.3 });

		font(keys).draw(key_list_window.stretched(-20));
		font(result).draw(result_window.stretched(-20));
		

		
	}
}
