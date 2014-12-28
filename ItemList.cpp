	cout << "[[#Number|Number]] ";
	for (auto ch = 'A'; ch <= 'Z'; ch++)
	{
		cout << "[[#" << ch << "|" << ch << "]] ";
	}
	cout << endl;
	cout << "==Number==" << endl;
	cout << "<div class=\"mw-collapsible mw-collapsed\">" << endl;


	ifstream input("input.txt");
	string last_line;
	while (!input.eof())
	{
		string line;
		getline(input, line);
		if (line.empty())
			continue;

		if (line == last_line)
			continue;	//skip duplicated item

		if (!last_line.empty() && last_line[0] != line[0])
		{
			if (line[0] >= 'A' && line[0] <= 'Z')
			{
				cout << "</div>" << endl;
				cout << "==" << line[0] << "==" << endl;
				cout << "<div class=\"mw-collapsible mw-collapsed\">" << endl;
				
			}
		}

		last_line = line;

		string original_name = line;
		auto n = original_name.find("(");
		if (n != string::npos)
		{
			string name = line.substr(0, n-1);
			string rank = line.substr(n+1, line.length()-n-2);
			line = original_name + "|<nowiki>" + name + " [" + rank + "]</nowiki>";
		}

		n = original_name.find("+");
		if (n != string::npos)
		{
			string level = original_name.substr(n+1);
			original_name = original_name.substr(0, n-1);
			if (original_name.find("Keyblade") != string::npos)
			{
				original_name += " " + level;
			}
		}
		cout << "*[[Image:" << original_name << ".gif]][[" << line << "]]" << endl;
	}
	cout << "</div>" << endl;