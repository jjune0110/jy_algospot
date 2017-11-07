#!/usr/bin/python
from xml.etree import ElementTree
import sys

fileName = sys.argv[1]+'.xml'

with open(fileName, 'rt') as f:
 tree = ElementTree.parse(f)

 print '<table>' 
 print '<tr><th>Branch</th><th>Version</th><th>Reporter</th><th>Jira</th></tr>'

 for node in tree.findall('ticket'):
  node2 = node.find('branch')
  branch = node2.text
  node2 = node.find('version')
  version = node2.text
  node2 = node.find('reporter')
  reporter = node2.text
  node2 = node.find('jira')
  jira = node2.text
  link = '<a href=http://hlm.lge.com/issue/browse/'+jira+' target="_blank">'+jira+'</a>'
  print '<tr><td>' + branch + '</td><td>' + version + '</td><td>' + reporter + '</td><td>' + link + '</td></tr>'

 print '</table>'