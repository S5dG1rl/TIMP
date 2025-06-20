#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <QMap>
#include <QVector>
#include <QSet>
#include <QString>
#include <QPair>
#include <QList>

/**
 * @brief ����� ��� ������������� ����� � ������ ����������� ���� ���������� ��������
 */
class Graph {
public:
    /**
     * @brief ����������� ������ Graph
     */
    Graph();

    /**
     * @brief ��������� ����� � ����
     * @param from �������-��������
     * @param to �������-����������
     * @param weight ��� ����� (�� ��������� 1)
     */
    void addEdge(int from, int to, int weight = 1);

    /**
     * @brief ������� ���������� ���� �� start �� end � ������� ��������� ��������
     * @param start ��������� �������
     * @param end �������� �������
     * @return ������ � ����� � ������� "start -> ... -> end" ��� ��������� �� ������
     */
    QString dijkstra(int start, int end);

private:
    /**
     * @brief ������ ��������� �����
     * ������ ������� � ������ ��� (�����, ��� �����)
     */
    QMap<int, QList<QPair<int, int>>> adjList;
};

#endif // DIJKSTRA_H
