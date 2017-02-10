void runQueries(ifstream &infile)
{
    // infile ��һ��ifstream��ָ������Ҫ����ĳ���
    TextQuery tq(infile); // �����ļ���������ѯmap
    // ���û���������ʾ�û�����Ҫ��ѯ�ĵ��ʣ���ɲ�ѯ����ӡ���
    while(true) {
        cout << "Enter word to look for, or q to quit: ";
        string s;
        // �������ļ�β���û�������'q'ʱѭ����ֹ
        if (!(cin >> s) || s == "q") break;
        // ָ���ѯ����ӡ���
        print(cout, tq.query(s)) << endl;
    }
}

class TextQuery
{
    
};

class QueryResult
{
    
};