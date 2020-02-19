pipeline {
    agent any 
    stages {
        stage('Build') { 
            steps {
                sh 'make bin'
            }
        }
        stage('CppCheck') { 
            steps {
                sh 'make cppcheck-xml'
            }
        }
        stage('Doxygen') { 
            steps {
                sh 'make doc'
            }
        }
	stage('Tests') {
            steps {
                sh 'make tests-xml'
            }
	}
    }

    post {
      always {
        publishCppcheck pattern: 'reports/cppcheck/report.xml'
        junit 'reports/tests/*.xml' 
        publishHTML target: [
            allowMissing: false,
            alwaysLinkToLastBuild: false,
            keepAll: true,
            reportDir: 'html',
            reportFiles: 'index.html',
            reportName: 'Doxygen documentation'
          ]  
      }
    }
}
