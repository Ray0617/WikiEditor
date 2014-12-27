	cout << "[[#Number|Number]] ";
	for (auto ch = 'A'; ch <= 'Z'; ch++)
	{
		cout << "[[#" << ch << "|" << ch << "]] ";
	}
	cout << endl;
	cout << "==Number==" << endl;

	ifstream input("ItemList.txt");
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
				cout << "==" << line[0] << "==" << endl;
		}

		last_line = line;

		auto n = line.find("(");
		if (n != string::npos)
		{
			string link = line;
			string name = line.substr(0, n-1);
			string rank = line.substr(n+1, line.length()-n-2);
			line = link + "|<nowiki>" + name + " [" + rank + "]</nowiki>";
		}
		cout << "*[[" << line << "]]" << endl;
	}