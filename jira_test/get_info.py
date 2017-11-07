#!/usr/bin/python
from xml.etree import ElementTree
import sys

fileName = sys.argv[1]+'.xml'

with open(fileName, 'rt') as f:
 tree = ElementTree.parse(f)

 for node in tree.findall('ticket'):
  node2 = node.find('branch')
  branch = node2.text
  node2 = node.find('version')
  version = node2.text
  node2 = node.find('reporter')
  reporter = node2.text
  node2 = node.find('jira')
  jira = node2.text
  print branch, version, reporter, jira
